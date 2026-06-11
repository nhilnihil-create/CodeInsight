 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool ispal(string a)
{
    long long int n=a.length();
    if(n==1)
        return true;
    else{
    int i=0,j;
    j=n-1;
    while(1)
    {
        if(a[i]!=a[j])
        {
            cout<<i<<" "<<j;
           return false;
        }
        i++,j--;
        if(i==j)
         {
        //     cout<<i<<" ";
             break;
        }
    }
    return true;
}}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin>>n;
  string a;
  cin>>a;
  if(n%2==1)
  {
      cout<<"No";
  }
  else{
int   i=0,j=n/2,f=0;
  while(1){
        if(j==n)
        {
            break;
        }
    if(a[i]!=a[j])
    {
        f=1;
        break;
    }
    i++,j++;
  }
  if(f==1)
  {
      cout<<"No";
  }
  else
    cout<<"Yes";
  }
  }
