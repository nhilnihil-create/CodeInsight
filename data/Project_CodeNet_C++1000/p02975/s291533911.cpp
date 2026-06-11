#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> vx;
    int A[N],B[N];
    for(int i = 0; i < N;i++){
        cin >> A[i];
        vx.push_back(A[i]);
    }
    
    sort(A,A+N);
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    if(vx.size()>3){
        cout << "No" << endl;
        return 0;
    }
    
    for(int i = 0; i < vx.size();i++){
        
        for(int j = 0; j < vx.size();j++){
            
            int a = vx[i],b = vx[j];
            B[0]=a,B[1]=b;
            for(int k = 2;k<N;k++)B[k]=B[k-2]^B[k-1];
            bool up = true;
            for(int k = 0; k < N;k++){
                
                int S = B[k];
                int T = B[(k-1+N)%N]^B[(k+1)%N];
                if(S!=T)up=false;
            }

            if(up){
                sort(B,B+N);
                for(int k = 0; k < N;k++)if(B[k]!=A[k])up = false;
                if(up){
                    cout <<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout <<"No"<<endl;
    return 0;
}