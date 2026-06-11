#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<vector<int>> x;
vector<vector<int>> y;

int counter(int x){
    if(x==0){
        return 0;
    }
    return counter(x >> 1)+(x & 1);
}

void input(){
    cin>>N;
    A.resize(N);
    x.resize(N);
    y.resize(N);
    for(int i=0; i<N; i++){
        
        cin>>A[i];


        for(int j=0; j<A[i]; j++){
            int x_in,y_in;
            
            cin>> x_in >> y_in;
        
            x_in--;

            x[i].push_back(x_in);
            y[i].push_back(y_in);
            
        }
    }

}

void solve(){
    int ans=0;
    for(int bits=1; bits<(1<<N); bits++){
        bool ok =true;

        for(int i=0; i<N; i++){
            if(!(bits & (1<<i))){
                continue;
            }
            for(int j=0; j<A[i]; j++){
                if(((bits >> x[i][j]) & 1) ^ y[i][j]){ // & 1　必要な理由?
                    ok = false;
                }
            }
        }
        if(ok){
            ans=max(ans, counter(bits));
        }
    }
    cout<< ans <<endl;
}

int main(){
    input();
    solve();
    return 0;
}