  #include<bits/stdc++.h>
  using namespace std;
  #define       M                        1000000007
  #define       ll                       long long
  #define       FIO                      ios_base::sync_with_stdio(false);cin.tie(NULL)
  #define       ifor(st,lim)             for(int i=st;i<lim;i++)
  #define       jfor(stt,llim)           for(int j=stt;j<llim;j++)
  #define       eifor(st,lim)            for(int i=st;i<=lim;i++)
  #define       ejfor(stt,llim)          for(int j=stt;j<=llim;j++)
  #define       blank                    cout<<'\n' 

  void solve()
  { 
      string s; cin>>s;
      int sum = 0;
      for(char c : s) sum+=c-'0';
      if(sum%9 == 0) cout<<"Yes";
      else cout<<"No";
  } 

  int main()
  {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int t=1; 
    while(t--){
      solve();
     } 
  }