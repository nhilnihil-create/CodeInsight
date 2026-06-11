#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
////////////////////////////////

    int h,w,m;
    cin >> h >> w >> m;

    set<pair<int,int>>s;
    map<int,int>row,col;
    int mxrow=-1,mxcol=-1;

    for (int i=0;i<m;i++){

        int a,b;
        cin >> a >> b;

        s.insert(make_pair(a,b));
        row[a]++;
        col[b]++;
        mxrow = max(mxrow,row[a]);
        mxcol = max(mxcol,col[b]);
    }

    vector<int>x,y;

    for (auto k : row) if (k.second == mxrow)x.push_back(k.first);
    for (auto k : col) if (k.second == mxcol)y.push_back(k.first);

    int ans = mxrow + mxcol - 1;

    bool f = 0 ;
    for (int i=0;i<(int)x.size();i++){
        for (int j=0;j<(int)y.size();j++){
            auto pp = make_pair(x[i],y[j]);
            if (s.find(pp)==s.end()){ 
                ans++;
                f=1;
                break;
            }
        }
        if (f) break;
    }

    cout<<ans<<'\n';    
}
