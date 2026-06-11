#include <bits/stdc++.h>

#define f(i,n) for(i=0;i<n;i++)

using namespace std;

struct Color {
  int r = 0;
  int g = 0;
  int b = 0;
};

typedef struct Color Color;

int main(){
  	int i,j,k,n;
  	long long int ans = 0;
  	string s;
  	cin >> n;
  	cin >> s;
 	vector<Color> v(n);
	if (s[0]=='R'){
      v[0].r++;
    }
    else if(s[0]=='G'){
    	v[0].g++;
    }
    else{
      v[0].b++;
    }
  	for (i=1;i<n;i++){
    	v[i] = v[i-1];
     	if (s[i]=='R'){
          v[i].r++;
        }
        else if(s[i]=='G'){
            v[i].g++;
        }
        else{
          v[i].b++;
        } 
    }
  	for (i=0;i<n-2;i++){
    	for (j=i+1;j<n-1;j++){
          	if (s[i]!=s[j]){
              if (s[i]+s[j]=='R'+'G'){
              		ans += v[n-1].b - v[j].b;               	
              }
              else if (s[i]+s[j]=='R'+'B'){
              		ans += v[n-1].g - v[j].g;               	
              }
              else{
              		ans += v[n-1].r - v[j].r;               	
              }
              k = 2*j-i;
              if (k<n && s[j]!=s[k] && s[i]!=s[k]){
              	ans--;
              }
            }
        }
    }
  	cout << ans << endl;
	return 0;
}