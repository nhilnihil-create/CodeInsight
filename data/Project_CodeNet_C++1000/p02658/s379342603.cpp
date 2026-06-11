#include<stdio.h>

int main(){
long int N;
scanf ("%d",&N);
long long int A[N];
long long int B = 1;
long long int x = 1000000000000000000;

for (int i = 0; i < N; i++ ){
scanf ("%lld",&A[i]);
if (A[i]==0){
    printf ("0\n");
    return 0; 
}
}
for (int i = 0; i< N; i++){
    if ( x < A[i] ){
        printf ("-1\n"); 
        return 0;
    }
     else {
	x= x/ A[i];
	B = B*A[i];
}
}
printf ("%lld\n",B);
return 0;
}