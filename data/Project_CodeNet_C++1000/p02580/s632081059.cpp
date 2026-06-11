#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int,int>P;

int main()
{
int h,w,m;
cin>>h>>w>>m;
vector<int>hs(h);
vector<int>ws(w);
set<P>s;
rep(i,m)
{
int r,c;
cin>>r>>c;
r--;c--;
hs[r]++;
ws[c]++;
s.emplace(r,c);

}
int hm=0,wm=0;
rep(i,h)
hm=max(hm,hs[i]);
rep(j,w)
wm=max(wm,ws[j]);
vector<int>hv;
vector<int>wv;
rep(i,h)
if(hs[i]==hm)hv.push_back(i);
rep(j,w)
if(ws[j]==wm)wv.push_back(j);
int ans=hm+wm;
for(int x:hv)
{
for(int y:wv)
{
if(s.count(P(x,y)))continue;
cout <<ans;
return 0;


}


}
ans--;
cout <<ans;
return 0;
}