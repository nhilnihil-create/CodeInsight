#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define SP ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main()
{
    SP;
    
    int x;
    int kyu;
    cin>>x;
    
    if(x>=400 && x<600)
    	kyu=8;
    else if(x>=600 && x<800)
    	kyu=7;
    else if(x>=800 && x<1000)
    	kyu=6;
    else if(x>=1000 && x<1200)
    	kyu=5;
    else if(x>=1200 && x<1400)
    	kyu=4;
    else if(x>=1400 && x<1600)
    	kyu=3;
    else if(x>=1600 && x<1800)
    	kyu=2;
    else if(x>=1800 && x<2000)
    	kyu=1;

    cout<<kyu;

	return 0;
}