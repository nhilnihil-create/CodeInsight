#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    long long int n;
    cin>>n;
    vector<long long int> vec(n);
    long long int sum=0,ans=0,x,center,center2;
    rep(i,n){
        cin>>x;
        sum+=x;
        vec[i]=sum;
    }
    vector<long long int> vec2(n);
    rep(i,n){
        vec2[i]=abs(sum-2*vec[i]);
    }
    sort(all(vec2));
    cout<<vec2[0]<<endl;
}
