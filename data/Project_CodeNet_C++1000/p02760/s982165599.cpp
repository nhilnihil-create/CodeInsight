#include <bits/stdc++.h>
using namespace std;
int n,a[100][100],b[200],k,l,x,y,z,h,t,c;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
        cin>>a[i][j];
    }
}
cin>>n;
for(int i=1;i<=n;i++){
    cin>>b[i];
}
sort(b,b+n);
for(int i=1;i<=n;i++){
if(a[1][1]==b[i])k++;
if(a[2][2]==b[i])k++;
if(a[3][3]==b[i])k++;

if(a[1][1]==b[i])l++;
if(a[1][2]==b[i])l++;
if(a[1][3]==b[i])l++;

 if(a[2][1]==b[i])x++;
 if(a[2][2]==b[i])x++;
 if(a[2][3]==b[i])x++;
 
 if(a[3][1]==b[i])y++;
 if(a[3][2]==b[i])y++;
 if(a[3][3]==b[i])y++;
 
 if(a[1][2]==b[i])c++;
 if(a[2][2]==b[i])c++;
 if(a[3][2]==b[i])c++;
 
 if(a[1][3]==b[i])t++;
 if(a[2][3]==b[i])t++;
 if(a[3][3]==b[i])t++;
 
 if(a[1][3]==b[i])z++;
 if(a[2][2]==b[i])z++;
 if(a[3][1]==b[i])z++;
 
 if(a[1][1]==b[i])h++;
 if(a[2][1]==b[i])h++;
 if(a[3][1]==b[i])h++;  
 
}
if(k==3||l==3||x==3||y==3||c==3||t==3||z==3||h==3)cout<<"Yes";
else cout<<"No";
return 0;}

