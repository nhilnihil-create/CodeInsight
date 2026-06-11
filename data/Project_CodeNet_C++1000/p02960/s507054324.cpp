    #include<bits/stdc++.h>
    #define ll long long
    #define rep(i,a,b) for(i=a;i<b;i++)
    #define pb push_back
    #define all(v) v.begin(),v.end()
    #define F first
    #define S second
    #define vi vector < ll  int >
    #define CLR(a) memset((a),0,sizeof(a))
    #define mp make_pair
    #define hell 1000000007
    using namespace std;

    #define MAXN 1000005
    int spf[MAXN];
    void sieve()
    {
        spf[1] = 1;
        for (int i=2; i<MAXN; i++)
            spf[i] = i;
        for (int i=4; i<MAXN; i+=2)
            spf[i] = 2;

        for (int i=3; i*i<MAXN; i++)
        {
            if (spf[i] == i)
            {
                for (int j=i*i; j<MAXN; j+=i)

                    if (spf[j]==j)
                        spf[j] = i;
            }
        }
    }


    vector<int> gf(int x)
    {
        vector<int> ret;
        while (x != 1)
        {
            ret.push_back(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }
    int BIT[100050];
    void upd(int x) { ++x;  while(x<=MAXN)  {  BIT[x]++;  x+=(x&-x);  } }
    int cal(int x) {  ++x;  int res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; }

    ll mod=hell;
    ll pr( ll x , ll y)
    {
        ll ans=1;
        if(y==0) return ans;
        while(y>1)
        {
            if(y&1) ans*=x;
            x*=x;
            y/=2;
            x%=mod;
            ans%=mod;
        }
        ans*=x;
        ans%=mod;
        return ans;
    }
    ll inv(ll n)
    {
        return pr(n,mod-2);
    }
    ll stoi(string s)
    {
        int n=s.size();
        ll k=0; int i;
        rep(i,0,n)
        {
            k+=s[i]-'0';
            k*=10;
        }
        return k/10;
    }
    string to_string(ll n)
    {  if(!n) return "0";
        string s=""; int a,b;
        while(n>0)
        {
            b=n%10;
            s+=(b+'0');
            n/=10;
        }
        reverse(all(s));
        return s;
    }
  ll invvf[1000500],fact[1000500];
  void pre()
  {
      ll i,j,n=1000050;
      fact[0]=1; fact[1]=1;
      rep(i,2,n) {fact[i]=fact[i-1]*i; fact[i]%=hell;}
      invvf[1]=1; invvf[0]=1;
      rep(i,2,n)
      {
          invvf[i]=inv(fact[i]);
      }

  }
 ll ncr(ll n , ll r)
 {
     ll y=fact[n];
     y*=invvf[r];
     y%=hell;
     y*=invvf[n-r];
     y%=hell;
     return y;
 }


int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
    void solve()
    {
    long long  i,j=0,r=200,p,q,k=0,d,y=0,n,h=100000000000000,flag=0,m=0,a=hell,b=hell,id,h1,h2,a1,b1,a2,w,x,u,f,l,c=0,e,ans=0;
      string s;
      cin>>s; n=s.size();
      vector  < ll > cnt(13,0),cnt1(13,0);
      y=1;
      if(s[0]=='?') rep(i,0,10) cnt[i]++;
      else cnt[s[0]-'0']++;
      rep(i,1,n)
      {   //cout<<i<<" ";
          if(s[i]=='?')
          {
              rep(j,0,10)
              {

                   rep(k,0,13)
                   {
                      a=cnt[k];
                      b=k*10;
                      b+=j;
                      b%=13;
                      cnt1[b]+=cnt[k];
                      cnt1[b]%=hell;

                   }
              }
              cnt=cnt1;
          }
          else{
            rep(k,0,13)
            {
                      a=cnt[k];
                      b=k*10;
                      b+=s[i]-'0';
                      b%=13;
                      cnt1[b]+=cnt[k];
                      cnt1[b]%=hell;
            }
            cnt=cnt1;
          }
          rep(j,0,13) cnt1[j]=0;
       //   rep(j,0,13) cout<<cnt[j]<<" ";
       //   cout<<endl;
      }
      cout<<cnt[5];
    }
    signed main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t=1;
        //sieve();
        //pre();
       // cin>>t;
        while(t--)
        solve();
    }
