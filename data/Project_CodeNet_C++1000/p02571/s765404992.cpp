#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,t;
	cin>>s;
	cin>>t;
	int l1=s.length();
	int l2=t.length();
	int no=0,max=l2;
//    cout<<s<<" "<<t<<endl;
	for(int i=0;i<=l1-l2;i++)
	{
		for(int j=0;j<l2;j++)
		{
//		  cout<<"i= "<<i<<" j= "<<j<<" t["<<j<<"]= "<<t[j]<<" s["<<i+j<<"]= "<<s[i+j]<<endl;
		  if(t[j]!=s[i+j])
		  {
		  	no++;
		  }	
		}
		if(no<max)
		{
			max=no;
		}
	    no=0;
	}
	cout<<max<<endl;
}
