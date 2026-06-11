#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string s;
    cin>>s;
    int len = s.length();

    int arr[len+1];
    memset(arr,-1,sizeof(arr));

    if(s[0]=='<')
    	arr[0] = 0;
    if(s[len-1]=='>')
    	arr[len] = 0;

    for(int  i = 0;i<len;i++)
    {
    	if(s[i]=='>' && s[i+1]=='<')
    		arr[i+1] = 0;
    	if(s[i]=='<' && arr[i]!=-1)
    		arr[i+1] = arr[i]+1;    	
    }

    for(int i = len-1;i>=0;i--)
    {
    	if(s[i]=='>')
    		arr[i] = max(arr[i],arr[i+1]+1);
    }
     long long sum = 0;
    for(int  i = 0;i<=len;i++){
    	sum+=arr[i];
    	//cout<<arr[i]<<" ";
    }
    cout<<sum<<endl;

}