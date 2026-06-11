# include <iostream>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <string>
using namespace std;


int main(){
    int n;
    
	while(1){
        cin >>n;
        if(n ==0) break;
        else
        {int sum =0 ;
            double a,avg,x =0;
            double b[n];
                    for(int i =0;i<n;i++){
                        cin >>b[i];
                        sum += b[i];
                    }
                    avg = (double)sum /(double)n;
                    for(int j=0;j<n;j++){
                       x += pow(b[j]-avg,2);
                    }
                    a= (double)x/(double)n;
                     printf("%.7f\n",pow(a,0.5));
        }

    }

	return 0;
}

