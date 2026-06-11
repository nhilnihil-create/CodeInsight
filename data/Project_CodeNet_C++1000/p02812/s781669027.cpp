 #include<bits/stdc++.h>
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
  int n;
  cin>>n;
    string a;
  cin>>a;
  int c=0;
  for(int i=0;i<n-2;i++)
  {
  	if(a[i]=='A' && a[i+1]=='B' && a[i+2]=='C')
    {
    	c++;
    }
  }
  cout<<c;

}
