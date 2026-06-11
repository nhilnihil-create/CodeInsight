//ada kartu bingo 3x3
//pada row ke i dari atas
//dan pada column ke j dari kiri
//berisikan Aij (angka kali)
//akan dipilih N, dari b1 hingga bN
//jika salah satu itu terpenuhi dari bingo sheet kita
//kita tandain
//tentukan jika kita bingo yaitu dengan cara menentukan apakah kita punya ada 3 yg berturut2 entah gmn itu arahnnya
//inputnya semua integer
//inputnya pake array3x3
//jika bingo Yes, jika tidak No

#include <stdio.h>
int main(){
	int card[3][3] = {0};
	for(int i = 0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			scanf("%d", &card[i][j]);		//minta input user buat bingo card
		}
	}

	//bingo card kosong buat nandain
	int pin[3][3] = {0};

	//bikin N, dan brp angka aja yg disebut biar dapet bingo apa ngga
	int N;
	scanf("%d", &N);		//banyak angka

	int pick; //input user
	//diulang biar dapet banyak N
	for(int k = 0; k<N; k++)
	{
		scanf("%d", &pick);

		for(int l = 0; l<3; l++)	//ceritanya dicocokin sama bingo card sebelah
		{
			for(int m = 0; m<3; m++)
			{
				if(card[l][m]==pick)	//kalo sama
				{
					pin[l][m]++;		//si pin ditandain
				}
			}
		}
	}



	//cek kebawah
	for(int i =0; i<3; i++)
	{
		if(pin[i][0]>=1)
		{
			if(pin[i][1]>=1)
			{
				if(pin[i][2]>=1)
				{
					puts("Yes");
					return 0;
				}
			}
		}
	}

	//cek vertikal
	for(int i =0; i<3; i++)
	{
		if(pin[0][i]>=1)
		{
			if(pin[1][i]>=1)
			{
				if(pin[2][i]>=1)
				{
					puts("Yes");
					return 0;
				}
			}
		}
	}

	//cek duagonal dari kiri
		if(pin[0][0]>=1)
		{
			if(pin[1][1]>=1)
			{
				if(pin[2][2]>=1)
				{
					puts("Yes");
					return 0;
				}
			}
		}

	//cek duagonal dari kanan
		if(pin[0][2]>=1)
		{
			if(pin[1][1]>=1)
			{
				if(pin[2][0]>=1)
				{
					puts("Yes");
					return 0;
				}
			}
		}

	puts("No");

	return 0;
}
