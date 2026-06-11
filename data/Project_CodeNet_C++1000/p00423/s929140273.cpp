#include<iostream>
using namespace std;

int main(){
	int n, a, b, at, bt;
	
loop:
	scanf("%d\n", &n);		// 各人のカード枚数
	if(n == 0) goto end_scope;
	at = 0;
	bt = 0;
	
labl_testloop:
	scanf("%d %d\n", &a, &b);
	if(a > b) at += a + b; else if(a == b){at += a; bt += b;}else bt += a + b;
	n--;
	if(n > 0) goto labl_testloop;
	
	printf("%d %d\n", at, bt);
	goto loop;
end_scope:
    return 0;
}