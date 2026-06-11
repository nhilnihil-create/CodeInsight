#include<iostream>
#include<cstring>
using namespace std;
char s1[1010],s2[1010]; // two words, s1 & s2 
int dis[1010][1010]; // array for the Levenshtein distance

int main(){
  cin>> s1 >> s2;
 
  int m=strlen(s1);
  int n=strlen(s2);

  for(int j=1;j<=m;j++){
    dis[j][0]=j;
  }
  for(int j=1;j<=n;j++){
    dis[0][j]=j;
  }
  for(int j=1;j<=m;j++){
    for(int k=1;k<=n;k++){
      dis[j][k] = min(
dis[j-1][k]+1,
min(dis[j][k-1]+1, 
    (s1[j-1]==s2[k-1] ? dis[j-1][k-1] : dis[j-1][k-1] + 1 ))); // comparing letters of the two words; +1 if different at respective location
    }
  }
  cout<<dis[m][n]<<endl;
  return 0;
}