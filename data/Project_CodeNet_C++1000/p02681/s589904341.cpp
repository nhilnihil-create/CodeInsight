#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
  string a,b;
  cin>>a>>b;
  int f=0;
  if(a.length()+1== b.length()){
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i])
            f=1;
    }
    if(f)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
  }

  else {
    cout << "No" << endl;
  }

    return 0;

}
