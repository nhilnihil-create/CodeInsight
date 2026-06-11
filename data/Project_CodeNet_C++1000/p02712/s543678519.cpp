//jika 3 dan 5 bisa membagi i, dan a ke i = FizzBuzz
//jika tidak, tapi 3 bisa = Fizz
//jika 5 doang = Buzz
//jika gaada, a ke i = i
//cari jumlah semua angka dengan batas N


#include <stdio.h>
int main(){
	int batas;
	scanf("%d", &batas);
	long long int count = 0;
	
	for(int i =0; i<=batas; i++)
	{
		if(i%3 == 0 && i%5 == 0)
		{
			count+=0;
		}
		else if(i%3 == 0)
		{
			count+=0;
		}
		else if(i%5 == 0)
		{
			count+=0;
		}
		else 
		{
			count+=i;
		}
	}
	
	printf("%lld\n", count);
	
	return 0;
}