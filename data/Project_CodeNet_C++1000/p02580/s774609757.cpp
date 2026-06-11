#include<bits/stdc++.h>
using namespace std;
pair<int,int>items[300001];
int Hcount[300001]={0},Wcount[300001]={0};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

int  H,W,M;
cin>>H>>W>>M;
set<pair<int,int>> present;

for(int i=0;i<M;i++)
{
   cin>>items[i].first>>items[i].second;
}

for(int i=0;i<M;i++)
{   
     items[i].first--;
     items[i].second--;
    Hcount[items[i].first]++;
    Wcount[items[i].second]++;
    present.insert({items[i].first,items[i].second});
}
int posH = max_element(Hcount,Hcount+H) - Hcount;
int posW = max_element(Wcount,Wcount+W) - Wcount;

int  ans = Hcount[posH] + Wcount[posW];
bool flag = false;
vector<int>Hpos,Wpos;
for(int i=0;i<H;i++)
{
      if(Hcount[i] == Hcount[posH])
      Hpos.push_back(i);
      
    
}
for(int i=0;i<W;i++)
{
      if(Wcount[i] == Wcount[posW])
      Wpos.push_back(i);
    
}
for(int i=0;i<Hpos.size();i++)
{
    for(int j=0;j<Wpos.size();j++)
    {
        if(present.find({Hpos[i],Wpos[j]}) == present.end())
           {flag =true;break;}    
      
    }
}
// cout<<flag<<endl;
// for(int i=0;i<H;i++)
// cout<<Hcount[i]<<' ';
// cout<<endl;
// for(int i=0;i<W;i++)
// cout<<Wcount[i]<<' ';
// cout<<endl;

if(!flag)
ans--;
cout<<ans<<endl;
return 0;
}