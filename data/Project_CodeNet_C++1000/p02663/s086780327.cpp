#include <stdio.h>

int main(){
    
	int h1, h2, m1, m2, k;
	scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	int rangem;
	int rangeh;
	
	if(m2<m1){
		m2+=60;
		h2-=1;
		rangem = m2-m1;
	}
	else{
		rangem = m2 - m1;
	}
	
	rangeh = h2-h1;
	int total = rangeh*60 + rangem;
	
	printf("%d\n", total - k);
	
    return 0;
}