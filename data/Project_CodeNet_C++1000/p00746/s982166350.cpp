#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int main()
{
    while(true){
        int N;cin>>N;
        if(!N)break;
        int nx=0,ny=0;
        vector<pair<int,int>>squs;
        squs.emplace_back(0,0);
        for(int i=0;i<N-1;++i){
            int n,d;cin>>n>>d;
            auto from=squs[n];
            from.first+=dx[d];
            from.second+=dy[d];
            squs.push_back(from);
        }
        int minx=0,miny=0,maxx=0,maxy=0;
        for(int i=0;i<N;++i){
            auto squ(squs[i]);
            minx=min(minx,squ.first);
            miny=min(miny,squ.second);
            maxx=max(maxx,squ.first);
            maxy=max(maxy,squ.second);

        }
        int H=maxy-miny+1;
        int W=maxx-minx+1;
        cout<<W<<" "<<H<<endl;
    }
    return 0;
}