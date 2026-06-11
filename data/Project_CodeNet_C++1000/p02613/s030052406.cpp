#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	int n;
  	cin >> n;
  	string s;
  	int a=0,w=0,t=0,r=0;
  	for(int i=0;i<n;i++){
    	cin >> s;
      if(s=="AC")
        a++;
      else if(s=="WA")
        w++;
      else if(s=="TLE")
        t++;
      else
        r++;
    }
  	cout<<"AC x "<<a<<endl;
    cout<<"WA x "<<w<<endl;
    cout<<"TLE x "<<t<<endl;
    cout<<"RE x "<<r;
    return 0;
}