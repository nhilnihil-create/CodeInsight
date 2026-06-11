#include <iostream>
#include <vector>
using namespace std;
main(){for(;;){int n,m,i=0,j,o=0,v,cnt=0,it;cin>>n>>m;vector<int> hmap(1),wmap(1),map;if(!n)return 0;for(;i<n;i++){cin>>v;o+=v;hmap.push_back(o);}o=0;for(i=0;i<m;i++){cin>>v;o+=v;wmap.push_back(o);}map.resize(max(hmap[n],wmap[m])+5);for(i=0;i<n;i++){for(j=i+1;j<n+1;j++){map[hmap[j]-hmap[i]]++;}}for(i=0;i<m;i++){for(j=i+1;j<m+1;j++){it=wmap[j]-wmap[i];if(map[it]>0)cnt+=map[it];}}cout<<cnt<<endl;}return 0;}