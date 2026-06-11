#include<bits/stdc++.h>
#include<string>
typedef long long ll;
#define  fi0(i,n)  for(int i=0;i<n;i++)
#define   pb()    push_back()
#define   mk()    make_pair()
#define   fst      first
#define   scnd    second
#define   fast    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define   endl     '\n';
using namespace std;
ll d(ll i)
{
}
void solve()
{
   int t;cin>>t;int k=1;while(t--){
   double t_r,r,b;
   cin>>t_r>>r>>b;
    double c_r,r_r;
   if(t_r<=r){
      r_r=0;
   }
   else{
      double d=t_r-r+1;
      r_r=d/(b/6);
   }
    b=300-b;
    if(b<=0){
      c_r=0;
    }
    else{
      c_r=(r)/(b/6);
    }
    cout<<setprecision(2)<<fixed<<c_r<<' '<<r_r<<endl;
}
}
void f()
{
    vector<string>xxx;
    cin.ignore();
    string s,test;
    getline(cin,s);
    reverse(s.begin(),s.end());
    for(int i=0; i<s.size(); i++)
    {
        if(i==s.size()-1)
        {
            test+=s[i];
            xxx.push_back(test);
            break;
        }
        if(s[i]!=' ')
        {
            test+=s[i];
        }
        else if(s[i]==' ')
        {
            xxx.push_back(test);
            test="";
        }
    }
    for(int i=0; i<xxx.size(); i++)
    {
        reverse(xxx[i].begin(),xxx[i].end());
        cout<<xxx[i]<<' ';
    }
}
void ff()
{
    int terget,run,ball;
    cin>>terget>>run>>ball;
    int r_run=terget-run+1;
    double over=50-(double)(ball)/6;
    double c_r_r=(double) run/over;
    double r_r_r=r_run/((double)(ball)/6);

    cout<<setprecision(2)<<fixed<<c_r_r<<' '<<r_r_r<<endl;
}
void mrge(int *arr,int low,int mid,int high){
    int i=low,k=low,j=mid+1,test[high];
    while(i<=mid&&j<=high){
      if(arr[i]<arr[j]){
        test[k++]=arr[i++];
      }
      else{
        test[k++]=arr[j++];
      }
    }
    while(i<=mid){
      test[k++]=arr[i++];
    }
    while(j<=high)test[k++]=arr[j++];
    for(int i=low;i<=high;i++)arr[i]=test[i];
}
void srt(int *arr,int low,int high){
  int mid;
   if(low<high){
  mid=(low+high)/2;
  srt(arr,low,mid);
  srt(arr,mid+1,high);
  mrge(arr,low,mid,high);
   }
   else return;
}
bool isprime(ll n){
  bool x=0;
  if(n==1)return x;
  for(int i=2;i*i<=n;i++){
    if(!(n%i))return x;
  }
  return !x;
}
vector<ll>save(){
      vector<ll>a;
      for(ll i=2;i<=100000;i++){
      if(isprime(i))a.push_back(i);
    }
    return a;
}
ll n=100007;
bool sa[100007];
void saive(){
    sa[2]=1;
    for(ll i=3;i<=n;i+=2){
            bool x=0;
        for(ll j=2;j*j<=i;j++){
            if(i%j==0){x=1;break;}
        }
        if(!x){sa[i]=1;}
    }
}
int main()
{
    fast;
    int n;cin>>n;
  cout<<!n<<endl;
}
