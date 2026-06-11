#include <iostream>
#include<vector>
#include <cstdlib>
#include<cmath>
#include<string>
#include <iomanip>
#include <sstream>

using namespace std;





int main () {


   long long n,i,j;
    cin>>n;

    string s="";
    char t;

char a[26]={'a', 'b', 'c', 'd' , 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm' , 'n', 'o', 'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y', 'z'};





while (n>0){

    j=n%26;
    n=n/26;
    if( j==0 ){

        s=a[25]+s;
        n-=1;
    }

    else {

        s=a[j-1]+s;

    }




}

cout<<s;


}


















/*#include <iostream>
#include<vector>
#include <cstdlib>
#include<cmath>
#include<string>
#include <iomanip>
#include <sstream>

using namespace std;


int main (){


    unsigned long long n,i,j,m,cnt=0;

    cin>>n;

    vector<unsigned long long> a(n);

    stringstream s[n];

    string final[n];

    for(i=0;i<n;i++){

        cin>>a[i];
    }

    for(i=0;i<n;i++){

        s[i]<<a[i];
        s[i]>>final[i];

    }

    vector<long long>b(n,0);



    for(i=0;i<n;i++){

        m=final[i].size();

        for(j=0;j<m;j++){

            b[i]+=final[i][j]-'0';


        }



    }

    for(i=0;i<n;i++){


        cout<<b[i]<<endl;
    }



}
 */