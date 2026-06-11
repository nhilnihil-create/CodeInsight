#include <stdio.h>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)

int main(void){
	FOR(i, 1, 10) FOR(j, 1, 10) printf("%dx%d=%d\n", i, j, i*j);
}