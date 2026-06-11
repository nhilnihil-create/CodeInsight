//integer positif N
//string S panjangnya N isinya lowercase

//tentukan apakah ia gabungan dari 2 string
//yaitu tentukan apakah ada string T yang memenuhi S = T + T

//N max 100
//S sepanjang N
//T itu kemungkinan T = N/2

//input
//integer N, string S

//output
//if S adalah gabungan dari 2 T, print Yes, jika tidak, No

//jadi istilahnya
//inputnya contoh
//6 = panjangnya 6 char
//abcabc		anggpalah T = abc, nah S kan T*T itu jadi abcabc
//jadi sederhananya
//kalo index 123...N di T1, = index 123...N di T2 print Yes, jika tidak No

//dan kalo int nya ganjil, pasti no, soalnya gabisa dibagi 2


#include <stdio.h>
#include <string.h>
int main(){
	int N, sama=0;
	scanf("%d", &N);
	
	if(N%2 != 0)
	{
		puts("No");
		return 0;
	}
	
	char str[N+1];
	scanf("%s", &str);
	int length = strlen(str);
	
	for(int i = 0, j = length/2; i <= length/2; i++, j++)
	{
		if(str[i] == str[j])
		{
			sama++;
		}
	}
	
	if(sama == length/2)
	{
		puts("Yes");
	}
	else 
	{
		puts("No");
	}
	
	return 0;
}