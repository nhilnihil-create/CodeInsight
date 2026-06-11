#include <bits/stdc++.h>
using namespace std;
using  P=pair<int,int>;
int main(){
  int N;
  cin>>N;
  vector<int> A(N-1);
  vector<int> B(N-1);
  vector<vector<int>> vec(N,vector<int>(0));
  vector<vector<int>> color(N,vector<int>(0));
  vector<unordered_map<int,int>> usedcolor(N);
  vector<int> way(N);
  map<P,int> mp;
  using Graph=vector<vector<int>>;
  Graph G(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    A.at(i)=a;
    B.at(i)=b;
    vec.at(a-1).push_back(b-1);
    vec.at(b-1).push_back(a-1);
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }
  int maxusedcolor=0;
  for(int i=0;i<N;i++){
    maxusedcolor=max(maxusedcolor,(int)vec.at(i).size());
    //cout<<i<<" "<<vec.at(i).size()<<endl;
  }
  cout<<maxusedcolor<<endl;
  vector<int> dist(N,-1);//全頂点を「未訪問」に初期化
  queue<int> que;
  dist[0]=0;
  que.push(0);
  while(!que.empty()){
    int v=que.front();//キューから先頭頂点を取り出す
    que.pop();
    //v から辿れる頂点をすべて調べる
    for(int nv:G[v]){
      int rock=0;
      //cout<<v<<" "<<nv<<endl;
      if(dist[nv]!=-1)continue;//すでに発見済みの頂点は探索しない
      if(color.at(v).size()==0){
        way.at(nv)=1;
        color.at(v).push_back(1);
        //sort(color.at(v).begin(),color.at(v).end());
        color.at(nv).push_back(1);
        //sort(color.at(nv).begin(),color.at(nv).end());
        usedcolor.at(v)[1]=1;
        usedcolor.at(nv)[1]=1;
        //cout<<v<<" "<<nv<<endl;
        mp[make_pair(v,nv)]=1;
      }
      else{
        if(usedcolor.at(v)[maxusedcolor]==0){
          way.at(nv)=maxusedcolor;
          color.at(v).push_back(maxusedcolor);
          //sort(color.at(v).begin(),color.at(v).end());
          color.at(nv).push_back(maxusedcolor);
          //sort(color.at(nv).begin(),color.at(nv).end());
          usedcolor.at(v)[maxusedcolor]=1;
          usedcolor.at(nv)[maxusedcolor]=1;
          //cout<<" "<<v<<" "<<nv<<endl;
          mp[make_pair(v,nv)]=maxusedcolor;
        }
        else{
          int left=0,right=(int)color.at(v).size()-1;
          rock=0;
          while(left<=right){
            int mid=left+(right-left)/2;
            //cout<<v+1<<" "<<nv+1<<" "<<mid+1<<" "<<color.at(v).at(mid)<<endl;
            if(color.at(v).at(mid)>mid+1){right=mid-1;}
            else{left=mid+1;rock=max(rock,mid+1);}
          }
          rock++;
          //color.at(v).push_back(rock);
          color.at(v).insert(color.at(v).begin()+rock-1,rock);
          left=0,right=(int)color.at(nv).size()-1;
          int rocka=0;
          while(left<=right){
            int mid=left+(right-left)/2;
            //cout<<v+1<<" "<<nv+1<<" "<<mid+1<<" "<<color.at(v).at(mid)<<endl;
            if(color.at(nv).at(mid)>rock){right=mid-1;}
            else{left=mid+1;rocka=max(rocka,mid+1);}
          }
          color.at(nv).insert(color.at(nv).begin()+rocka,rock);
          ////sort(color.at(v).begin(),color.at(v).end());
          //color.at(nv).push_back(rock);
          ////sort(color.at(nv).begin(),color.at(nv).end());
          usedcolor.at(v)[rock]=1;
          usedcolor.at(nv)[rock]=1;
          //cout<<"   "<<v<<" "<<nv<<endl;
          mp[make_pair(v,nv)]=rock;
        }
      }
      dist[nv]=dist[v]+1;
      que.push(nv);
    }
  }
  for(int i=0;i<N-1;i++){
    cout<<mp[make_pair(A.at(i)-1,B.at(i)-1)]<<endl;
  }
}