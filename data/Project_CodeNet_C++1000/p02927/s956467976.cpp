  /*
    *   |.-|-..|..|-.--|---|--.|..|...|....|..|...-|.-| 
    */
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    
  	int m,d,count = 0,d1,d2;
  	cin >> m >> d;
  	if(d >= 22){
  		for(int i = 22;i <= d;i++){
          	d1 = i%10;
          	d2 = i/10;
        	if(d1 >= 2 && (d1*d2) <= m && (d1*d2) > 0){
            	count++;
            }
        }	
      	cout << count << "\n";
    }else{
    	cout << "0\n";
    }
	return 0;
}