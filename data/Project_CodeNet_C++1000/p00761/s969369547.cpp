#include "bits/stdc++.h"

using namespace std;

int calc(string a,int l){
    vector<int> v(l,0);
    for(int i=0;i<(int)a.length();i++){
        v[i]=a[i]-'0';
    }
    sort(v.begin(),v.end());
    int tmp=0;
    for(int i=0;i<l;i++){
        tmp*=10;
        tmp+=v[i];
    }
    sort(v.rbegin(),v.rend());
    int tmp2=0;
    for(int i=0;i<l;i++){
        tmp2*=10;
        tmp2+=v[i];
    }
    return tmp2-tmp;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int a,l;
    while(cin>>a>>l,a||l){
        vector<int> v(100);
        v[0]=a;
        for(int i=1;i<=100;i++){
            v[i]=calc(to_string(v[i-1]),l);
        }
        for(int i=1;i<=20;i++){
            for(int j=0;j<i;j++){
                if(v[i]==v[j]){
                    cout<<j<<" "<<v[i]<<" "<<i-j<<endl;
                    goto done;
                }
            }
        }
        done:continue;
    }
}