#include <iostream>
#include <algorithm>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
using P = pair<int,int>;

int main()
{
    int N;
    cin>>N;
    P r[100010];
    rep(i,N){
        int x,l;
        cin>>x>>l;
        r[i] = make_pair(x+l,x-l);
    }

    sort(r,r+N);

    int ans=1,min=0;
    for(int i=1;i<N;i++){
        if(r[min].first<=r[i].second){
            min = i;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}