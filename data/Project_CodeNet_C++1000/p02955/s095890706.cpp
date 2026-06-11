#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K; cin >> N >> K;
    long long sum=0;
    long long a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
        sum+=a[i];
    }
    sort(a,a+N);
    vector<long long> div;
    for(long long i=1;i*i<=sum;i++){
        if(sum%i==0){
            div.push_back(i);
            if(sum/i!=i) div.push_back(sum/i);
        }
    }
    sort(div.begin(),div.end());
    long long ans=0;
    for(int i=0;i<div.size();i++){
        //cout << div[i] << endl;
        long long tmp[N];
        for(int j=0;j<N;j++){
            tmp[j]=a[j]%div[i];
        }
        sort(tmp,tmp+N);
        for(int j=1;j<N;j++){
            tmp[j]+=tmp[j-1];
        }
        long long a,b;
        bool flag=false;
        for(int j=0;j<N;j++){
            a=tmp[j];
            b=div[i]*(N-1-j)-(tmp[N-1]-tmp[j]);
            if(max(a,b)<=K){
                flag=true;
                break;
            }
        }
        if(flag) ans=max(ans,div[i]);
    }
    cout << ans << endl;
}