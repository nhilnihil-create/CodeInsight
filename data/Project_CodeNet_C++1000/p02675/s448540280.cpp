#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>


using namespace std;
#define PI acos(-1)

int main()
{
	int S;
	cin >> S;
	int a =S%10;
	switch(S%10){
	    case 0:
	    case 1:
	    case 6:
	    case 8:
	    cout<<"pon"<<endl;
	    break;
	    
	    case 2:
	    case 4:
	    case 5:
	    case 7:
	    case 9:
	    cout<<"hon"<<endl;
	    break;
	    case 3:
	    cout<<"bon"<<endl;
	    break;
	}

}

