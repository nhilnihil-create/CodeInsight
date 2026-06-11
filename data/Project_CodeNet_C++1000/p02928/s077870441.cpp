#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define md 1000000007
#define  vl vector <ll>
#define  pb push_back

int main()
{
    ll n, i,  j, k, m, p=0, c, pp, x, y, h=0, hh;
    cin>>n>>k;
    vl a(n), b(n);
    for(i=0; i<n; i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin(), b.end());
    p=0;
    for(i=0; i<n; i++){
        h=0;
        for(j=i+1; j<n; j++){
            if(a[j]<a[i])h++;
        }
        y=lower_bound(b.begin(), b.end(), a[i])-b.begin();
        x=y*(k-1)+h;

        if((x+h)%2==1){
            hh=k/2;
            p+=(((h+x)%md)*hh)%md;
            p%=md;
        }
        else{
            hh=(h+x)/2;
            p+=((hh%md)*k)%md;
            p%=md;
        }
    }
    cout<<p<<endl;
    return 0;
}





