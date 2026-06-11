#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	string x; cin>>x;
	if(x[x.size()-1]=='s'){
		cout<<x+"es"<<endl;
	}
	else{
		cout<<x+"s"<<endl;
	}
    return 0;
}
