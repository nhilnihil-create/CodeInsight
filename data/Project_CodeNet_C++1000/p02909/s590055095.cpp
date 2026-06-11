#include <bits/stdc++.h>
using namespace std;
int main() 
{
int i;
string n;
vector<string> arr(4);
arr[0]="Sunny";
 arr[1]="Cloudy";
 arr[2]="Rainy";
 arr[3]="Sunny";
 cin>>n;
 for(i=0;i<3;i++)
 {
     if(arr[i]==n)
     {
         cout<<arr[i+1]<<endl;
         break;
     }
 }
}
