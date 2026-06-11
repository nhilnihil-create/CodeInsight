#include <bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin >> n;
int arr[n];

int j=0;
for(int i=0;i<n;i++)
{
    cin >> arr[i];
    if(arr[i]%2==0) {
        j++;
    }
}
int temp=0;
for(int i=0;i<n;i++)
{
    if(arr[i]%2==0)
    {
        if(arr[i]%3==0||arr[i]%5==0) temp+=1;
    }
}
if(temp==j) cout << "APPROVED";
else cout << "DENIED";
	return 0;
}
