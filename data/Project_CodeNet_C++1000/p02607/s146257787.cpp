#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    
int n;
cin>>n;
vector<int> arr(n,0);

for(int i=0;i<n;i++)
cin>>arr[i];

int count=0;
for(int i=0;i<n;i+=2)
{
    if(arr[i]%2==1)
    count++;
}
cout<<count<<endl;

}