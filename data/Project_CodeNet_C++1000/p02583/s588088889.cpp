#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;

    vector<int> L(N);

    for(int i=0;i<N;i++){
        cin >> L.at(i);
    }

    int ans=0;

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                bool tf = true;
                if(L.at(i)==L.at(j))tf=false;
                if(L.at(j)==L.at(k))tf=false;
                if(L.at(k)==L.at(i))tf=false;
                if(L.at(i)+L.at(j)<=L.at(k))tf=false;
                if(L.at(k)+L.at(i)<=L.at(j))tf=false;
                if(L.at(j)+L.at(k)<=L.at(i))tf=false;

                if(tf==true){
                    ans++; 
                }
            }
        }
    }

    cout << ans << endl;
    
} 