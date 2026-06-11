#include <stdio.h>
#include <string.h>

int main(){
	
	int Atk, Hth;
	scanf ("%d %d", &Atk, &Hth);
	
	int Tot = Atk/Hth;
	
	int Rst = Atk % Hth;
	
	Rst > 0 ? printf("%d", Tot+1) : printf("%d", Tot);
	
	return 0 ;
}

//  \N JANGAN LUPA!!!!!