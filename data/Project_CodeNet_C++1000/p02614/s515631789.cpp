#include <iostream>

#include<vector>

#include<string>

#include<algorithm>

#include<cmath>

#include<cstdlib>

#include<utility> 

#include<cstdio> 

#define vii vector< pair<int,int> >

#define vi vector<int>

#define INF 1000000007

#define ff first

#define ss second

#define lli long long int

#define ulli unsigned long long int

using namespace std;

 char a[7][7],b[7][7];

 int n,m,k;

 void copy_max(){

   for(int i=0; i<n; i++){

     for(int j=0; j<m; j++){

       b[i][j]=a[i][j];

     }

   }

 }

 void fill_max(int a1, int b1){

   //have to check if that row is set or not

     for(int i=0; i<n; i++){

       if(a1&(1<<i)){

         //fill all rows with red

        for(int j=0; j<m; j++)

        b[i][j]='R';

         

       }

     }

     //do same for column

     for(int i=0; i<m; i++){

       if(b1&(1<<i)){ //if subset is set

         for(int j=0; j<n; j++)

         b[j][i]='R';

       }

       

     }

 }

  bool check(){

   int cnt=0;

    for(int i=0; i<n; i++){

      for(int j=0; j<m; j++){

        if(b[i][j]=='#')

        cnt++;

      }

    }

    if(cnt==k)

    return true;

    return false;

  }

int main() {

 ios_base::sync_with_stdio(false);

    cin.tie(NULL);

   cin>>n>>m>>k;

   for(int i=0; i<n; i++){

     for(int j=0; j<m; j++){

       cin>>a[i][j];

     }

   }

   int cnt=0;

   //now check for all the possible subsets of this matrix

   int subn=1<<n, subm=1<<m;

   for(int i=0; i<subn; i++)

     for(int j=0; j<subm; j++){

       copy_max();

       fill_max(i,j);

       if(check())

       cnt++;

     }

  cout<<cnt<<endl;

}