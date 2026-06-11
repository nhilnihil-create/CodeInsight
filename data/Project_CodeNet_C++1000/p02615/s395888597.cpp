#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n;
    vector<ll> num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll temp;
        scanf("%lld",&temp);
        num.push_back(temp);
    }
    sort(all(num),greater<ll>());
    int count=0; // maksimal 2;
    int index=0; // num[index]
    ll res=0;
    for(int i=1;i<=1&&i<n;i++){
        res+= num[0];
        index++;
        //printf("res %lld\n",res);
    }
    for(int i=2;i<n;i++){
        count++;
        res+=num[index];
        if(count==2){
            index++;
            count=0;
        }
        //printf("res %lld\n",res);
    }
    printf("%lld\n",res);
}
