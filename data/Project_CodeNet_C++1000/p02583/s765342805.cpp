#include<bits/stdc++.h>

using namespace std;

bool check(int a,int b,int c){
    int maxi=max(a,max(b,c));
    if((a+b+c)-max(a,max(b,c))>max(a,max(b,c))){
        return true;
    }
    return false;
}

int main(){
    int n;cin>>n;
    int niz[n],rj=0;
    for(auto& a:niz)
        cin >>a;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(niz[i]!=niz[j] && niz[j]!=niz[k] && niz[i]!=niz[k] && check(niz[i],niz[j],niz[k])){
                    rj++;
                }
            }
        }
    }
    cout <<rj<<endl;
}
