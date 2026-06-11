#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    int a[q];
    int b[q];
    int c[q];
    int d[q];
    for(int i= 0;i<q;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    long kotae = 0;
    for(int i1 = 1;i1<=m;i1++){
    	for(int i2 = i1;i2<=m;i2++){
        	for(int i3=i2;i3<=m;i3++){
            	for(int i4=i3;i4<=m;i4++){
                	for(int i5 = i4;i5<=m;i5++){
                    	for(int i6 = i5;i6<=m;i6++){
                        	for(int i7 = i6;i7<=m;i7++){
                            	for(int i8=i7;i8<=m;i8++){
                                	for(int i9=i8;i9<=m;i9++){
                                    	for(int i10=i9;i10<=m;i10++){
                                        int A[] = {i1, i2, i3, i4, i5,i6,i7,i8,i9,i10};
                                        long g = 0;
                                        	for(int k = 0;k<q;k++){
                                              if(A[b[k]-1]-A[a[k]-1] == c[k]) g+= d[k];
                                            }
                                        kotae= max(kotae,g);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }     
        }  
    }
    cout<<kotae;
    return 0;
}