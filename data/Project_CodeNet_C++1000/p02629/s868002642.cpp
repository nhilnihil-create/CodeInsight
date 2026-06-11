//1,000,000,000,000,001	dogs dinomorin
//trs dinamain 1-26 a-z
//27-702 aa, ab, ac-zy, zz
//703-18278 aaa, aab, aac-zzy, zzz
//18279 - 475254 aaaa, aaab-zzzy, zzzz
//dst
//trs ditanya, utk anjing ke N, siapa namanya
//1<=N<=1000000000000001
//inputnya int sekali doang

#include <stdio.h>
int main(){
	long long int pilih;
	scanf("%lld", &pilih);	//nomor ajgnya
	
	char namaAnjing[16]={0};	//kosong semua
	
	pilih--;	//biar dia sesuai sama indeks
	
	int i = 0;
	while(pilih > -1)
	{
		namaAnjing[i] = pilih % 26 + 'a';	//isi dari namaAnjing ke i itu huruf
											//dia bakal bagi 26 biar jadi angka yg bisa diubah jadi huruf
											//kl a bagi 26 kan 0 sisa baginya, abis soalnya, trs tambahin 'a' biar jadi huruf
											//kalo b kan 1, ditambah a jadi asciinya b, dst
		pilih = pilih / 26;					//ini fungsinya cmn 1 sebenernya, biar dia bisa abis, jd kl ga dibagi dia bakal gede terus angkanya, trs namanya panjang
											//kan salah eta, kita maunya urutan kan, makanya dibagi 26 jadi kayak tiap udah 1 huruf muncul, ya berarti udh 1 abjad terlewati kan
		i++; //biar dia isi nama indeksnya bener urutannya maju
		pilih--;		//biar dia tetep masuk dlm array
	}										
	
	
	while(i--)		//ini kan bakal kebalik munculnya di inya, jadi biar bener urutannya
	{					//print aja dari paling gede trs dikurangin, slesai
		printf("%c", namaAnjing[i]);		//di print terus sampe dia udah keluar dari array
	}
	
	//kalo udah biar aman, ato kalo user gila inputnya gaada
	printf("\n");
	
	return 0;
}
