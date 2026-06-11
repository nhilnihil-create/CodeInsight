#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);



int main()
{
    faster();

    int n;
    cin>>n;
    int rem;
    rem = n%10;
    if(rem==1 || rem==0 || rem==6 || rem==8){
        cout<<"pon"<<endl;
    }
    else if(rem==3){
        cout<<"bon"<<endl;
    }
    else{
        cout<<"hon"<<endl;
    }


    return 0;
}

