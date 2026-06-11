#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int P_MAX=10000;
int main()
{
  int tt=1,rr=0;
  int r[P_MAX];
  long long n,p,i,res=0;
  long long t[P_MAX];
  string s;
  cin >> n >> p;
  cin >> s;
  if(p==2||p==5){
    for(i=0;i<n;i++){
      tt=stoi(s.substr(i,1));
      if(tt%p==0)
        res+=i+1;
    }
    cout << res << endl;
    return 0;
  }
  fill(t,t+p,0);
  for(i=0;i<p-1;i++){
    r[i]=tt%p;
    tt=r[i]*10;
  }
  for(i=0;i<n;i++){
    tt=stoi(s.substr(n-1-i,1));
    rr+=tt*r[i%(p-1)];
    rr%=p;
    t[rr]++;
  }
  res=t[0]*(t[0]+1)/2;
  for(i=1;i<p;i++)
    res+=t[i]*(t[i]-1)/2;
  cout << res << endl;
  return 0;
}