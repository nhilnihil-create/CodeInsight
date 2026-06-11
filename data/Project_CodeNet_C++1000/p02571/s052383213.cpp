#include<bits/stdc++.h>
using namespace std;

int main()
{
  	string s,t;
  	cin>>s>>t;
  
  	int l1=s.size(),l2=t.size();
  	
  	int mi_cnt=l2;
  
  	for(int i=0;i+l2-1<l1;i++)
    {
      	int cnt=0;
      	for(int j=0;j<l2;j++)
        {
          	if(t[j] != s[i+j])
              	cnt++;
        }
      	mi_cnt=min(mi_cnt,cnt);
    }
  	cout<<mi_cnt<<endl;
  	return 0;
}