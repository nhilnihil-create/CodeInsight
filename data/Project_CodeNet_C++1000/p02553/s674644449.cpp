#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{int a[2],b[2],c,d,i,j,k,y;
 vector<int> arr,a1,a2;
 cin>>a[0]>>a[1]>>b[0]>>b[1];
 for(i=0;i<2;i++)
 {for(j=0;j<2;j++)
 {y=a[i]*b[j];
 arr.push_back(y);
 }
 }
 sort(arr.begin(),arr.end());
 cout<<arr[3];
 return 0;
}