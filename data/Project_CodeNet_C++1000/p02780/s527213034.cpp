#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int numsum(int a){
    if(a==1)return 1;
    else{
        return a+numsum(a-1);
    }
}
double expect(int a){
    return numsum(a)/(double)a;
}
int main(){
    int k,n;cin>>n>>k;
    vector<double>p(n);//
    double max=0;
    int a;
    double sum=0;
    rep(i,n){
        cin>>a;
        p.at(i)=expect(a);
        if(i<k-1){
            sum+=p.at(i);
        }else if(i>=k-1){
            sum+=p.at(i);
            if(max<sum){
                max=sum;
            }
            sum-=p.at(i-k+1);
        }
    }
    /* これだとo(nk)でTLE
    for(int i=0;i<n-k+1;i++){
        sum=0;
        for(int j=i;j<i+k;j++){
            sum+=p.at(j);
        }
        if(max<sum){
            max=sum;
        }
    }*/
    printf("%.12f\n",max);


}