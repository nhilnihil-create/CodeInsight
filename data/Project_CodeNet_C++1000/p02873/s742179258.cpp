#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--)
    {
    string str;
    cin>>str;
    int n=str.size();
    int arr[n+1]={0};
    for(int i=0;i<n;i++)
    {
        if(str[i]=='<'){
            arr[i]=0;
            int j=i+1;
            int val=1;
            while(str[j]==str[j-1]){
                arr[j]=val;
                val++;
                j++;
            }
            i=j-1;
        }

    }
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='>'&&i!=0){
            arr[i]=max(arr[i+1]+1,arr[i-1]+1);
        }else if(str[i]=='>'&&i==0){
        arr[i]=arr[i+1]+1;
        }

    }
    if(str[n-1]=='<'){
        arr[n]=arr[n-1]+1;
    }
    ll sum=0;
    for(int i=0;i<=n;i++){
        sum+=arr[i];
    }
    cout<<sum<<endl;

    }


    return 0;

}
