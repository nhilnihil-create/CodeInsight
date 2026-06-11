#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int N, K;
vector<int> a;

int main()
{
    int i,in,l,r,ans,count;
    cin >> N >> K;
    rep0(i, N) {scanf("%d",&in); a.push_back(in);}
    sort(a.begin(),a.end());

    r=a[N-1];l=0;ans=(l+r)/2;

    while(r-l>1)
    {
        count=0;
        rep0(i,N){
            count+=(a[i]-1)/ans;
            //cout<<count<<endl;
            if(count>K) break;
        }
        if(count<=K) {r=ans;ans=(l+r)/2;}
        else {l=ans;ans=(l+r-1)/2+1;}
    }
    
    cout << r << endl;

    return 0;
}