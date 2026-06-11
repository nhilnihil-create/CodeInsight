#include<bits/stdc++.h>
//#define pb push_back
using namespace std;
int h,x;
int a[1000002];
void maxheap(int i){
	 int l=2*i,t,m=i;
	 if (a[l]>a[i] && l<=h)
	    m=l;
	 if (a[l+1]>a[m] && (l+1)<=h)
        m=l+1;
     if (m!=i){
     	t=a[i]; a[i]=a[m]; a[m]=t;
	    maxheap(m);
	 }
	 	   
}
int main(){
	cin>>h;
	//a.pb(0);
	for (int i=1; i<=h; i++){
		cin>>a[i];
	} 
	for (int i=h/2; i>=1; i--)
	    maxheap(i);
	for (int i=1; i<=h; i++)
	    cout<<' '<<a[i];
    cout<<'\n';
    return 0;
}
