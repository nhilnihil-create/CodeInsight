#include <iostream>

//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <cstring>
//include <queue>
//#include <map>
//cout<<*itr<<endl;
//#define ll long long //data types used often, but you don't want to type them time by time
//#define ALL(c) (c).begin(),(c).end() //handy for function lisziee "sort()"
//#define FOREACH(itr,cont) for (auto itr=cont.begin(); itr!=cont.end(); itr++) // traverse an STL data structure
#define F(i,R) for (int i = 0; i < R; i++) //next four are for "for loops"

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
    int n, x,size;
    cin>>n>>x;
    int arr[n+1],s=0;
    arr[0]=0;
    for(int i=1; i<=n; i++) {
        cin>>size;
        s+=size;
        arr[i]=s;
    }
    int c=0;
    for(int i=0; i<=n; i++) if(arr[i]<=x)
    c++;
    if(c==0)
    cout<<1;
    cout<<c;
}