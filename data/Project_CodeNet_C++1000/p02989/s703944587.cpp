#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    rep(i,n){
        cin>>vec[i];
    }
    sort(all(vec));
    cout<<vec[n/2]-vec[n/2-1]<<endl;
}