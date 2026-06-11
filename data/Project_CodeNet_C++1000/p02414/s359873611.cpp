#include <iostream>
 
int main() {
	int n,m,l,t;
    long long int ta=0;
    std::cin >> n >> m >> l;
    int lista[n][m]={0};
    int listb[m][l]={0};
    for(int a=0;a<n;a++){
     for(int b=0;b<m;b++){
      std::cin >> lista[a][b];
     }
    }
    for(int c=0;c<m;c++){
     for(int d=0;d<l;d++){
      std::cin >> listb[c][d];
     }
    }
 
    for(int e=0;e<n;e++){
     for(int f=0;f<l;f++){
      for(int g=0;g<m;g++){
      ta=ta+lista[e][g]*listb[g][f];
      }
      std::cout << ta;
      if(f!=l-1)std::cout << " ";
      ta=0;
     }
     std::cout << std::endl;
    }
	return 0;
}