#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,d,a[11][11],i,j,k,count = 0,ans = 0;
    double s[50]={0},b[11][11];
    cin >> n >> d;
    for(i=0; i<n; i++){
       for(j=0; j<d; j++){
          cin >> a[i][j];
          b[i][j]=a[i][j];
        }
    }
    for(i=0; i<n-1; i++){
       for(j=i+1; j<n; j++){
          for(k=0; k<d; k++){
             s[ans]=s[ans]+(pow((b[i][k]-b[j][k]),2));
          }
          s[ans]=sqrt(s[ans]);
          if((round(s[ans])-(s[ans]))==0){
             count++;}
             ans++;
      }
    }
    cout << count << endl;
    return 0;
}
