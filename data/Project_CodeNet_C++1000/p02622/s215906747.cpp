#include <iostream>
#include<vector>
#include <cstdlib>
#include<cmath>
#include<string>
#include <iomanip>
#include <sstream>

using namespace std;


int main (){

  int n,i,j=0;

  string a[2];

  for(i=0;i<2;i++){

      cin>>a[i];

  }

  n=a[0].size();

  for(i=0;i<n;i++){

    if(a[0][i] != a[1][i]){


        j++;
    }


  }

  cout<<j;


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