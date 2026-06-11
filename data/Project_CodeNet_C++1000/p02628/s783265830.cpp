#include <iostream>
#include<vector>
#include <cstdlib>
#include<cmath>
#include<string>
#include <iomanip>
#include <sstream>

using namespace std;


void sort(vector<int> &a){

    int mini,k,j=0,i,n=a.size();

    for(i=0;i<n;i++){
        mini=50000000;
        for(j=i+1;j<n;j++){

            if( mini > a[j] ){

                mini=a[j];
                k=j;
            }


        }

        if(a[i] > mini){

            swap(a[i],a[k]);

        }

    }


}


int main () {

int k,n,i,j;

cin>>n>>k;

vector<int> a(n);


for(i=0;i<n;i++){

    cin>>a[i];
}

int u=0;

sort(a);

for(i=0;i<k;i++){

    u+=a[i];

}

cout<<u;


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