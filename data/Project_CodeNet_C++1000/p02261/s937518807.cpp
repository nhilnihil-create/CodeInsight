#include <iostream>
#include <string>
#include <cstring>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;

void bubble(int si[],char sc[],int N)
{
  for(int i=0;i<N;i++)
  {
    for(int j=N-1;j>i;j--)
    {
      if(si[j]<si[j-1])
      {
        swap(si[j],si[j-1]);
        swap(sc[j],sc[j-1]);
      }
    }
  }
}

void selection(int si[],char sc[],int N)
{
  for(int i=0;i<N;i++)
  {
    int mini = i;
    for(int j=i;j<N;j++)
    {
      if(si[j]<si[mini]) mini=j;
    }
    swap(si[i],si[mini]);
    swap(sc[i],sc[mini]);
  }
}

int main()
{
  int N; cin>>N;
  char sc_1[N],sc_2[N];
  int si_1[N],si_2[N];
  REP(i,N) cin>>sc_1[i]>>si_1[i];;

  memcpy(sc_2,sc_1,sizeof(char)*N);
  memcpy(si_2,si_1,sizeof(int)*N);

  bubble(si_1,sc_1,N);
  selection(si_2,sc_2,N);
  REP(i,N)
  {
    if(i) cout<<' ';
    cout<<sc_1[i]<<si_1[i];
  }
  cout<<endl;
  cout<<"Stable"<<endl;

  REP(i,N)
  {
    if(i) cout<<' ';
    cout<<sc_2[i]<<si_2[i];
  }
  cout<<endl;

  bool stable=true;
  REP(i,N) if(sc_2[i]!=sc_1[i]) stable = false;
  if(stable){
    cout<<"Stable"<<endl;
  }else{
    cout<<"Not stable"<<endl;
  }
}